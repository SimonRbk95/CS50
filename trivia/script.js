document.addEventListener("DOMContentLoaded", function(){
    // When correct answer is clicked
    let correct = document.getElementById("correct");
    correct.addEventListener("click", function(){
        correct.style.backgroundColor = "green";
        document.getElementById("placeholder1").innerHTML = "Correct!";
    });

    
    incorrect.addEventListener("click", function(){
        incorrect.style.backgroundColor = "red";
        document.getElementById("placeholder1").innerHTML = "incorrect!";
    });

});