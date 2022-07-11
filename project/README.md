# CS50 Final Project -- Online Digital Skills Consultant
Information technologies are still very foreign for many people working in various industries. Either reskilling or improving existing technical skills will be critical for people to be competitive in the market. Fortunately, there are many hands-on courses online that facilitate just that. However, the supply is overwhelming with thousands of these courses. The online digital skills consultant solves this problem by suggesting personalized courses from Coursera and free relevant Youtube videos that help get a first overview of the field of interest.

The Flask web application is mainly based on Python routing and creating the logic behind suggesting courses, Javascript for interactive buttons and forms, HTML, CSS, and Jinja 2 working with Python variables to create HTML dynamically.

Technologies used:
- Flask (as a framework)
- Python
- Javascript
- Jinja2
- HTML
- CSS
- other small libraries or packages

## How does it work:
User input:

The users gets prompted by a Get Started button that takes them to a questionnaire. All these mandatory questions serve to determine which courses and videos to suggest.

1. How comfortable are you with basic technologies?
2. How comfortable are you with programming?
    The first two questions can be answered with less, more, and very. Each answer triggers different keywords used to fetch video IDs via Youtube's data search API.
3. What are your areas of interest?
4. What are your goals?

The first two questions can be answered with less, more, and very. Each answer triggers different keywords used to fetch video IDs via Youtube's data search API.

The third question is a multiple-choice one, currently restricted to a maximum choice of three areas of interest. This arbitrary restriction serves only to avoid having a results page so long as to be offputting for the user.

The fourth question determines the user's goals, influencing the type of suggested courses.

All the answers are stored in Python Lists and dynamically allocated via Jinja2, ensuring easy maintenance and enabling course suggestions.

### Video Demo:

## Further improvements



