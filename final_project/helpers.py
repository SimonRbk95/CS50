import requests
import urllib.parse
import csv
import gzip
import shutil
import os

from flask import redirect, render_template, request, session
from os.path import exists

# input txt file name without extension
def read_txt(file):
    if not exists(f'static/{file}.txt'):
        with gzip.open(f'static/{file}.txt.gz', 'rb') as f_in:
            with open(f'static/{file}.txt', 'wb') as f_out:
                shutil.copyfileobj(f_in, f_out)
            f_out.close()
    contents = []
    with open(f'static/{file}.txt', newline= "") as f_out:
        reader = csv.DictReader(f_out, delimiter="\t")
        for row in reader:
            contents.append(dict(row))
        return contents

# input csv file name without extension
def read_csv(file):
    contents = []
    with open(f"static/{file}.csv") as f_out:
        reader = csv.DictReader(f_out)
        for row in reader:
            contents.append(row)
        return contents


def lookup(course):
    """Look up quote for symbol."""

    # Contact API
    try:
        api_key = os.environ.get("API_KEY")
        url = f"https://cloud.iexapis.com/stable/stock/{urllib.parse.quote_plus(course)}/quote?token={api_key}"
        response = requests.get(url)
        response.raise_for_status()
    except requests.RequestException:
        return None

def append_dict_cdb(dict, courses):
    courses.append({
    "Course Name": dict["Product Name"],
    "URL": dict["Product URL"],
    "Partner": dict["Manufacturer"],
    "Certificate": dict["Product Type"],
    "Image URL" : dict["Image URL"],
    "Current Price" : dict["Current Price"],
    "Product Description" : dict["Product Description"],
    })
    return courses

def append_dict_cdb100(dict, courses):
    courses.append({
    "Course Name": dict["Product Name"],
    "URL": dict["URL"],
    "Partner": dict["Partner"],
    "Certificate": dict["Product Type"],
    })
    return courses

def check_duplicates(courses, dict):
    for course in courses:
        if course["Course Name"] == dict["Product Name"]:
            return True
    return False

def check_dict(courses, choice, dict, List_q4, max_courses, cdb100=None):
        if choice == "Data Analytics/ Science":
            for i in ["Data Analytics", "Data Science"]:
                if cdb100:
                    if i in dict["Product Name"] or i in dict["Primary Domain"] or i in dict["Primary Subdomain"] and len(courses) < max_courses:
                            # only append courses with professional certificates if "get a new job" is the goal
                            if "Get a new job" in List_q4:
                                if dict["Product Type"] == "Professional Certificate" and len(courses) < max_courses:
                                    courses = append_dict_cdb100(dict, courses)
                            elif len(courses) < max_courses:
                                courses = append_dict_cdb100(dict, courses)
                elif i in dict["Product Name"] and len(courses) < max_courses:
                    courses = append_dict_cdb(dict, courses)
        elif cdb100:
            if choice in dict["Product Name"] or choice in dict["Primary Domain"] or choice in dict["Primary Subdomain"] and len(courses) < max_courses:
                if "Get a new job" in List_q4:
                    if dict["Product Type"] == "Professional Certificate" and len(courses) < max_courses:
                        courses = append_dict_cdb100(dict, courses)
                elif len(courses) < max_courses:
                    courses = append_dict_cdb100(dict, courses)
        elif choice in dict["Product Name"] and len(courses) < max_courses:
                courses = append_dict_cdb(dict, courses)
        return courses

def check_dict(courses, index, dict, List_q4, keywords_q3, max_courses, cdb100=None):
        if cdb100:
            if any(n in dict["Product Name"] or n in dict["Primary Domain"] or n in dict["Primary Subdomain"] for n in keywords_q3[index]):
                if cdb100 and len(courses) < max_courses:
                    # only append courses with professional certificates if "get a new job" is the goal
                    if "Get a new job" in List_q4:
                        if dict["Product Type"] == "Professional Certificate" and len(courses) < max_courses:
                            courses = append_dict_cdb100(dict, courses)
                    elif len(courses) < max_courses:
                        courses = append_dict_cdb100(dict, courses)
        elif any(n in dict["Product Name"] for n in keywords_q3[index]):
                courses = append_dict_cdb(dict, courses)
        return courses


