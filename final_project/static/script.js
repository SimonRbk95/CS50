document.addEventListener("DOMContentLoaded", function(){
    // When button is clicked
    let buttons = document.querySelectorAll(".btn-outline-light");
    for (let i = 0; i < buttons.length; i++){
        buttons[i].addEventListener("click", function(){
            window.location.href = '/q1';
            });
        }
    let style = document.createElement('style');
    document.head.appendChild(style);
    style.sheet.insertRule('.profile-badge {margin-left: auto; margin-right: auto}');
    });


