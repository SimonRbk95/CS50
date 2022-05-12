document.addEventListener("DOMContentLoaded", function(){
    // When correct answer is clicked
    let correct = document.getElementById("correct");
    correct.addEventListener("click", function(){
        correct.style.backgroundColor = "green";
        document.getElementById("placeholder1").innerHTML = "Correct!";
    });

    // inspired by Brian's walkthrough
    let incorrects = document.querySelectorAll(".incorrect");
    for (let i = 0; i < incorrects.length; i++){
        incorrects[i].addEventListener("click", function(){
            incorrects[i].style.backgroundColor = "red";
            document.getElementById("placeholder1").innerHTML = "incorrect!";
            });
        }

    // text field question
    let btn = document.getElementById("checkAnswer5");
    btn.addEventListener("click", function(){
        input = document.getElementById("Answer5")
        input.addEventListener("input", function(){
            if (input.innerHTML.toLowerCase() === "brown"){
                document.getElementById("placeholder2").innerHTML = "Correct!";
            }
            else{
                document.getElementById("placeholder1").innerHTML = "Incorrect!";
            }
        });
    });

});