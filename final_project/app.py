import os
import string

from flask_session import Session
from flask import Flask, flash, redirect, render_template, request, session
from cs50 import SQL

from helpers import read_csv

app = Flask(__name__)

app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

app.static_folder = 'static'

contents = read_csv("static/coursera_db")
# for type in contents: print(type["Image URL"]) print("done")

@app.route("/")
def index():

    return render_template("index.html")


@app.route("/about", methods=["GET", "POST"])
def about():
    return render_template("about.html")

@app.route("/q1", methods=["GET", "POST"])
def q1():
    answers = request.args.getlist("level")
    print(answers)
    return render_template("q1.html")

@app.route("/results")
def results():
    # based on input display Top 5 coursera courses
    # differentiate between professional certificate, specialization, standalone
    return render_template("results.html")

        # based on input display Top 5 edx courses

        # based on input display Top5 udacity courses
        # based on input display Top 5 coursera courses
        # differentiate between professional certificate, specialization, standalone

        # based on input display Top 5 youtube Videos
