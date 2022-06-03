import os
import string

from flask_session import Session
from flask import Flask, flash, redirect, render_template, request, session
from cs50 import SQL

app = Flask(__name__)

app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

app.static_folder = 'static'

@app.route("/")
def index():
    return render_template("index.html")


@app.route("/about", methods=["GET", "POST"])
def about():
    return render_template("about.html")

@app.route("/q1", methods=["GET", "POST"])
def q1():
    age = request.args.get("age")
    print(type(age))
    print(age)
    return render_template("q1.html")

@app.route("/result")
    def results():
        # based on input display Top 5 coursera courses
        # differentiate between professional certificate, specialization, standalone

        # based on input display Top 5 edx courses

        # based on input display Top5 udacity courses

        # based on input display Top 5 youtube Videos