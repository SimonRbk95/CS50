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