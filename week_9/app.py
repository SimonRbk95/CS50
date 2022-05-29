import os
import string

from flask import Flask, render_template, request
from cs50 import SQL

app = Flask(__name__)

@app.route("/")

def index():
    return render_template("index.html")

