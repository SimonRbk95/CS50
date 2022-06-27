import requests
import urllib.parse
import csv
import gzip
import shutil
import os
import google_auth_oauthlib.flow
import googleapiclient.discovery
import googleapiclient.errors
import pandas as pd
import seaborn as sns

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

def append_dict_cdb(dict, courses):
    courses.append({
    "Course Name": dict["Product Name"],
    "URL": dict["Product URL"],
    "Partner": dict["Manufacturer"],
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
    return any(course["Course Name"] == dict["Product Name"] for course in courses)

# def prof_cert_courses(courses, index, dict, keywords_q3, max_courses):
    # if any(n in dict["Product Name"] or n in dict["Primary Domain"] or n in dict["Primary Subdomain"] for n in keywords_q3[int(index)]) and len(courses) < max_courses:
        #if dict["Product Type"] == "Professional Certificate":
            # courses = append_dict_cdb100(dict, courses)
    # return courses

def condition(dict, courses, keywords_q3, index, max_courses, cdb100=None):
    if cdb100:
        if any(n in dict["Product Name"] or n in dict["Primary Domain"] or n in dict["Primary Subdomain"] for n in keywords_q3[int(index)]) and not check_duplicates(courses, dict) and len(courses) < max_courses:
            return True
    else:
        if any(n in dict["Product Name"] for n in keywords_q3[int(index)]) and not check_duplicates(courses, dict) and len(courses) < max_courses:
            return True

# requires cdb100 or cdb database as a list of dictionaries
def check_all_courses(courses, index, keywords_q3, max_courses, List_q4=None, cdb100=None, cdb=None):
            # append professional certificates first if get a new job is the goal
            # check if we are searching the cdb100 to use appropriate searches
            if cdb100:
                if "Get a new Job" in List_q4:
                    for dict in cdb100:
                        if condition(dict, courses, keywords_q3, index, max_courses, True):
                            if dict["Product Type"] == "Professional Certificate":
                                courses = append_dict_cdb100(dict, courses)
                for dict in cdb100:
                    if condition(dict, courses, keywords_q3, index, max_courses, True):
                        courses = append_dict_cdb100(dict, courses)
            # in big data base search only for matches in product name
            else:
                for dict in cdb:
                    if condition(dict, courses, keywords_q3, index, max_courses):
                        courses = append_dict_cdb(dict, courses)
            return courses

def YT_lookup(course):
    """Look up quote for symbol."""
    api_service_name = "youtube"
    api_version = "v3"

    # Contact API
    try:
        api_key = os.environ.get("API_KEY")
        youtube = googleapiclient.discovery.build(
        api_service_name, api_version, developerKey = api_key)
        request = youtube.search().list(
        part="id,snippet",
        type='video',
        q=course,
        videoDuration='short',
        videoDefinition='high',
        maxResults=3,
        relevanceLanguage="en"
        
        fields="items(id(videoId),snippet(title,description))")
        response = requests.get(url)
        response.raise_for_status()
    except requests.RequestException:
        return None

