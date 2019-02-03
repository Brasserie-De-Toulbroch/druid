#! /bin/bash

sqlite3 $1 <<END_SQL
CREATE TABLE recipes(id INTEGER PRIMARY KEY AUTOINCREMENT, title TEXT, notes TEXT, final_vol INTEGER, mashing_water_vol INTEGER, mashing_wort_vol INTEGER, mashing_temp INTEGER)
END_SQL

sqlite3 $1 <<END_SQL
CREATE TABLE malts(recipe_id INTEGER, name TEXT, ebc INTEGER, weight INTEGER, FOREIGN KEY(recipe_id) REFERENCES recipes(id) )
END_SQL
