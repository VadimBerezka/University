    // Задание 1
    function function1() {
        let col = document.querySelector(".first")
        col.style.color = "red"
    }

    // Задание 2
    function function2() {
        let size = document.querySelector(".second")
        size.style.fontSize = "40px"
    }

    // Задание 3 
    function function3() {
        let image1 = '<img id="fst" src="top-2.jpg" onclick="f4()">'
        document.getElementById('fst').src = 'top-3.jpg'
    }

    // Задание 4
    function function4() {
        let thd = document.getElementById('thd')
        thd.innerHTML = '<img src="top-4.jpg" style="width: 400px; height: 400px ;">'
    }

    // Задание 5
    function function5_1() {
        let size2 = document.querySelector(".third")
        size2.style.width = "600px"
    }

    function function5_2() {
        let size2 = document.querySelector(".third")
        size2.style.width = "200px"
    }

    // Задание 6
    function function6() {
        let col = document.querySelector(".first")
        col.style.border = "5px solid red "
    }