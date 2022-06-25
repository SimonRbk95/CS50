                # special answer that considers two keywords
                if choice == "Data Analytics/ Science":
                    for i in ["Data Analytics", "Data Science"]:
                        if i in dict["Product Name"] or i in dict["Primary Domain"] or i in dict["Primary Subdomain"]:
                                if "Get a new job" in List_q4:
                                    if dict["Product Type"] == "Professional Certificate" and len(courses) < 5:
                                        courses.append({
                                            "Course Name": dict["Product Name"],
                                            "URL": dict["URL"],
                                            "Partner": dict["Partner"],
                                            "Certificate" : dict["Product Type"],
                                            })
                                elif len(courses) < 5:
                                    courses.append({
                                    "Course Name": dict["Product Name"],
                                    "URL": dict["URL"],
                                    "Partner": dict["Partner"],
                                    "Certificate": dict["Product Type"],
                                    })

                elif choice in dict["Product Name"] or choice in dict["Primary Domain"] or choice in dict["Primary Subdomain"] and len(courses) < 5:
                    # only append courses with professional certificates if "get a new job" is the goal
                    if "Get a new job" in List_q4:
                        if dict["Product Type"] == "Professional Certificate" and len(courses) < 5:
                            courses.append({
                                "Course Name": dict["Product Name"],
                                "URL": dict["URL"],
                                "Partner": dict["Partner"],
                                "Certificate": dict["Product Type"],
                                })
                    elif len(courses) < 5:
                        courses.append({
                        "Course Name": dict["Product Name"],
                        "URL": dict["URL"],
                        "Partner": dict["Partner"],
                        "Certificate": dict["Product Type"],
                        })
        # list of three lists containing unique ids for each course
        rnd_Ids = []
        n = 0
        m = 20
        for i in range(len(choices)):
            Ids = random.sample(range(n, m),len(choices[i]))
            rnd_Ids.append(Ids)
            n +=20
            m +=20



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