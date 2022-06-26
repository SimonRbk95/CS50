import os
import string
import uuid

from flask_session import Session
from flask import Flask, flash, redirect, render_template, request, session
from cs50 import SQL

from helpers import read_csv, read_txt, append_dict_cdb, append_dict_cdb100, check_duplicates, prof_cert_courses, check_all_courses

app = Flask(__name__)

app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

app.static_folder = 'static'

# load up dictionaries
cdb = read_txt("cdb")
cdb100 = read_csv("cdb100")


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/about", methods=["GET", "POST"])
def about():
    return render_template("about.html")

@app.route("/qs", methods=["GET", "POST"])
def qs():
    options_q = ["less", "more", "very"]
    options_q3 = ["Machine Learning", "Data Analytics/ Science", "Blockchain", "Computer Science", "Programming with Python", "Internet of Things"]
    options_q4 = ["Get a new Job", "Boost my CV", "Learn about new technologies"]
    keywords_q3 = [["Machine Learning"],["Data Analytics", "Data Science"],["Blockchain"],["Computer Science"],["Python", "Programming with Python"],["Internet of Things"]]
    max_courses = 5
    # get user input
    if request.method == "POST":
        # returns the answers as an index number of list options_q
        q1 = request.form.get("q1")
        q2 = request.form.get("q2")

        # returns indeces of select elements in options_q3 that will be used as correspondants to the list of keywords
        List_q3 = request.form.getlist("q3")

        # get actual options chosen based on returned indeces
        List_q3_options = []
        for i in List_q3:
            List_q3_options.append(options_q3[int(i)])

        List_q4 = request.form.getlist("q4")

        # for choice in List_q3:
            # additional server-side input validation?
            # if choice not in options_q3:
                # return redirect("/qs")

        if q1 == "less":
            # suggest basic tech videos on Youtube
            pass

        if q2 == "less":
            # suggest intro programming courses
            pass

        # for each choice there will be a list of dictionaries with relevant courses
        choices = []
        for index in List_q3:
            # list of dictionaries with relevant course data
            courses=[]
            # check if there is a course in coursera's top 100 with a name smilair to the user's choice
            check_all_courses(courses, index, keywords_q3, max_courses, cdb100=cdb100)
            # get further data for chosen courses from cdb
            for dict in cdb:
                # keep track of at which index the list item, the dictionary called 'course', is
                i = 0
                for course in courses:
                    if dict["Product Name"] == course["Course Name"]:
                        # courses[i]["URL"] = dict["Short Link"]
                        courses[i]["Image URL"] = dict["Image URL"]
                        courses[i]["Current Price"] = dict["Current Price"]
                        courses[i]["Product Description"] = dict["Product Description"]
                        # courses[i]["SKU"] = dict["Unique Merchant SKU"]
                    i+=1
            if len(courses) < max_courses:
                courses = check_all_courses(courses, index, dict, keywords_q3, max_courses, cdb=cdb)

            # assign every dict a 'unique' identifier
            # (not worth it to check for duplicates - possibility of a match is extremely low)
            for dict in courses:
                new_id = uuid.uuid1()
                dict["ID"] = new_id.int

            # append the list of dictionaries to the outter list
            choices.append(courses)
        return render_template("results.html", choices=choices, List_q3_options=List_q3_options)
    else:
        return render_template("questionnaire.html", options_q=options_q, options_q3=options_q3, options_q4=options_q4)


