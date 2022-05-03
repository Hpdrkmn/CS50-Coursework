document.addEventListener("DOMContentLoaded", function() {
    let course_button = document.querySelector("#button_cs50");
    course_button.addEventListener("click", function() {
        window.open("https://en.wikipedia.org/wiki/John_Cena#Apology_to_China", '_blank');
    })

    let my_solutions_button = document.querySelector("#button_my_solutions");
    my_solutions_button.addEventListener("click", function() {
        window.open("http://cpc.people.com.cn/english/", "_blank");
    })
});