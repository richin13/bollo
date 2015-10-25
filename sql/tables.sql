CREATE TABLE bollo_bakery (
	bakery_id SERIAL,
    bakery_name VARCHAR(100) NOT NULL UNIQUE,
    bakery_state SMALLINT NOT NULL,
    bakery_city VARCHAR(60) NOT NULL,
    bakery_stock INT DEFAULT 0,
    CONSTRAINT bakery_PK PRIMARY KEY(bakery_id)
);
CREATE TABLE bollo_logbook (
	logbook_id SERIAL,
    logbook_description VARCHAR(100) NOT NULL,
    logbook_date TIMESTAMP(0) NOT NULL DEFAULT(CURRENT_TIMESTAMP AT TIME ZONE 'utc-6'),
    logbook_bakery INT,
    CONSTRAINT logbook_PK PRIMARY KEY (logbook_id),
    CONSTRAINT logbook_bakery_FK FOREIGN KEY(logbook_bakery)
    REFERENCES bollo_bakery(bakery_id)
    ON UPDATE CASCADE ON DELETE CASCADE
);
CREATE TABLE bollo_logbook_general (
    logbook_general_id INT NOT NULL,
    CONSTRAINT lb_general_FK FOREIGN KEY(logbook_general_id)
    REFERENCES bollo_logbook(logbook_id)
    ON UPDATE CASCADE ON DELETE CASCADE
);
CREATE TABLE bollo_logbook_problem (
  logbook_problem_id INT NOT NULL,
  problem_dough FLOAT NOT NULL,
  CONSTRAINT lb_problem_FK FOREIGN KEY(logbook_problem_id)
  REFERENCES bollo_logbook(logbook_id)
  ON UPDATE CASCADE ON DELETE CASCADE
);
CREATE TABLE bollo_user (
    user_id SERIAL,
    user_fname TEXT NOT NULL,
    user_lname TEXT) NOT NULL,
    user_username TEXT NOT NULL UNIQUE,
    user_password TEXT NOT NULL,
    user_email TEXT NOT NULL UNIQUE,
    user_token INT NULL,
    user_forgot_token TEXT NULL DEFAULT NULL UNIQUE,
    user_session_token TEXT NULL DEFAULT NULL UNIQUE,
    CONSTRAINT user_PK PRIMARY KEY(user_id, user_username)
);
CREATE TABLE bollo_inactive_account (
	iaccount_id SERIAL,
    iaccount_activation_token CHAR(20) NOT NULL UNIQUE,
    iaccount_user_id INT NOT NULL,
    iaccount_user TEXT NOT NULL,
    CONSTRAINT inactive_acc_PK PRIMARY KEY(iaccount_id),
    CONSTRAINT inactive_user_FK FOREIGN KEY(iaccount_user_id, iaccount_user)
    REFERENCES bollo_user(user_id, user_username)
    ON UPDATE CASCADE ON DELETE CASCADE
);

