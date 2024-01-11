import os

from cs50 import SQL

from flask import Flask, render_template, request, redirect, url_for, session
from flask_sqlalchemy import SQLAlchemy
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash


# Configure application
app = Flask(__name__)

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///todo.db")
    
@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response
    
    
# index page
@app.route("/")
def index():
    user_id = session.get("user_id")
    if not user_id:
        return render_template("index.html")
    else:
        return redirect(url_for("homepage"))
    

# register page
@app.route('/register', methods=["GET", "POST"])
def register():
    session.clear()

    if request.method == "POST":
        
        # get the name from the frontend, and check if have already exist in the database or didn't input, return error 400 if something wrong
        name = request.form.get("username")
        name_count = db.execute("SELECT COUNT(*) FROM user WHERE user_name = ?", name)[0]["COUNT(*)"]
        if not name or name_count > 0:
            return ("Illegal username, please check it.", 400)
        
        # get the password from the frontend, and check if the passwords which are inputted is same, return error 400 if something wrong
        password = request.form.get("password")
        double_password = request.form.get("double_password")
        if not password or password != double_password:
            return ("Please check your password", 400)
        
        # secret the password, store the hash into the database
        hash = generate_password_hash(password, method='pbkdf2', salt_length=16)
        db.execute("INSERT INTO user (user_name, user_password) VALUES (?, ?)", name, hash)
        return render_template("login.html")
    
    else:
        return render_template("register.html")
    
    
#login page
@app.route('/login', methods=["GET", "POST"])
def login():
    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return ("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return ("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM user WHERE user_name = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["user_password"], request.form.get("password")):
            return ("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["user_id"]

        # Redirect user to home page
        return redirect(url_for("homepage"))

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")
    
# log out page
@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")
    

@app.route('/homepage', methods=["GET", "POST"])
def homepage():
    user_id = session.get("user_id")
    
    priority_info = db.execute("SELECT priority_txt FROM priority;")
    book_info = db.execute("SELECT book_name FROM book;")
    
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        
        note = request.form.get("note")
        date = request.form.get("date")
        
        priority_id = db.execute("SELECT priority_id FROM priority WHERE priority_txt = ?", request.form.get("priority"))[0]["priority_id"]
        book_id = db.execute("SELECT book_id FROM book WHERE book_name = ?", request.form.get("book"))[0]["book_id"]
        
        db.execute("INSERT INTO todolist (note_txt, last_date, user_id, priority_id, book_id) VALUES (?, ?, ?, ?, ?)", note, date, user_id, priority_id, book_id)
         
    todos = db.execute("SELECT * "
                   "FROM todolist T "
                   "JOIN user U ON U.user_id = T.user_id "
                   "JOIN priority P ON P.priority_id = T.priority_id "
                   "JOIN book B ON B.book_id = T.book_id "
                   "WHERE U.user_id = ?", user_id)
    # Redirect user to home page
    return render_template("homepage.html", todos=todos, priority_info=priority_info, book_info=book_info)

@app.route('/delete/<int:todo_id>', methods=["POST"])
def delete(todo_id):
    if request.method == "POST":
        db.execute("DELETE FROM todolist WHERE todo_id = ?", todo_id)
        
        return redirect(url_for('homepage'))
    

    
    


