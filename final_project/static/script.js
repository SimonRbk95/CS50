document.addEventListener("DOMContentLoaded", function(){
    // When button is clicked
    let buttons = document.querySelectorAll(".btn-outline-light");
    for (let i = 0; i < buttons.length; i++){
        buttons[i].addEventListener("click", function(){
            window.location.href = '/q1';
            });
        }
    elem = document.querySelector('div.profile-badge');
    elem.style.marginRight = 'auto';
    elem.style.marginLeft = 'auto';

    $('select').selectpicker();

});


