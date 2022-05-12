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
    document.getElementById("checkAnswer5").addEventListener("click", function(){
        let input = document.querySelector("input");
        if (input.value.toLowerCase() === "brown"){
            document.getElementById("placeholder2").innerHTML = "Correct!";
            input.style.background = "green";
        }
        else{
            document.getElementById("placeholder2").innerHTML = "Incorrect!";
            input.style.background = "red";
        }
    });

});
