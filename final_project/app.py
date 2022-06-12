import os
import string

from flask_session import Session
from flask import Flask, flash, redirect, render_template, request, session
from cs50 import SQL

from helpers import read_csv, read_txt

app = Flask(__name__)

app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

app.static_folder = 'static'

cdb = read_txt("cdb")
# for type in contents: print(type["Image URL"]) print("done")


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/about", methods=["GET", "POST"])
def about():
    return render_template("about.html")

@app.route("/qs", methods=["GET", "POST"])
def qs():
    # get user input
    if request.method == "POST":
        # returns the answers as an index number of list options_q
        q1 = request.form.get("q1")
        q2 = request.form.get("q2")

        # returns string
        List_q3 = request.form.getlist("q3")

        # returns the answers as an index number of list options_q
        List_q4 = request.form.getlist("q4")
        print(q1, q2, List_q3, List_q4)

        # additional server-side input validation?
        for choice in List_q4:
            if choice not in options_q4:
                return redirect("/qs")

        # suggestions




        return render_template("results.html")
    else:
        options_q = ["less", "more", "very"]
        options_q3 = ["Machine Learning", "Data Analytics/ Science", "Blockchain", "Computer Science", "Programming with Python", "Internet of Things"]
        options_q4 = ["Get a new Job", "Boost my CV", "Learn about new technologies"]
        return render_template("questionnaire.html", options_q=options_q, options_q3=options_q3, options_q4=options_q4)

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
