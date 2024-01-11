-- create users table
CREATE TABLE user (
    user_id INTEGER PRIMARY KEY AUTOINCREMENT,
    user_name VARCHAR(255),
    user_password VARCHAR(255)
);

-- create todolist table
CREATE TABLE todolist (
    todo_id INTEGER PRIMARY KEY AUTOINCREMENT,
    note_txt TEXT,
    last_date DATE,
    user_id INTEGER REFERENCES user(user_id),
    priority_id INTEGER REFERENCES priority(priority_id),
    book_id INTEGER REFERENCES book(book_id),
    state_id INTEGER REFERENCES state(state_id)
);

-- create priority table
CREATE TABLE priority (
    priority_id INTEGER PRIMARY KEY AUTOINCREMENT,
    priority_txt VARCHAR(60),
    priority_color VARCHAR(60)
);

-- create book table
CREATE TABLE book (
    book_id INTEGER PRIMARY KEY AUTOINCREMENT,
    book_name VARCHAR(60)
);

-- create state table
CREATE TABLE state (
    state_id INTEGER PRIMARY KEY AUTOINCREMENT,
    state_txt VARCHAR(60)
);
