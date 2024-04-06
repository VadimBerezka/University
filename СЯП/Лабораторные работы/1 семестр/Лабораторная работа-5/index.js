function task1() {
    const allElements = document.querySelectorAll("*")
    for (let i = 0; i < allElements.length; i++) {
        console.log("Тег номер " + (i + 1) + ": " + allElements[i].tagName)
    }
}


function task2() {
    const childBodyElements = document.body.childNodes
    for (let i = 0; i < childBodyElements.length; i++) {
        console.log("Дочерний элемент номер " + (i + 1) + ": " + childBodyElements[i].nodeName)
    }
}

function task3() {
    const allElements = document.querySelectorAll("*")
    for (let i = 0; i < allElements.length; i++) {
        if (allElements[i].tagName === "SPAN") {
            alert("Первый способ " + allElements[i].textContent)
            break
        }
    }

    const spanElements = document.querySelectorAll("span")
    if (spanElements) {
        alert("Второй способ " + spanElements[0].textContent)
    }
  
    const span2Element = document.getElementById("sp")
    if (span2Element) {
        alert("Задание №3 " + span2Element.textContent)
    }
}

function task4() {
    
    let pl1 = parseFloat(document.getElementById("1").innerHTML);
    let pl2 = parseFloat(document.getElementById("2").innerHTML);
    let pl3 = parseFloat(document.getElementById("3").innerHTML);
    let pl4 = parseFloat(document.getElementById("4").innerHTML);
    let pl5 = parseFloat(document.getElementById("5").innerHTML);
    let srpl = (pl1 + pl2 + pl3 + pl4 + pl5) / 5;

    let ob=(document.getElementById("span2").innerHTML + ' ' + 'Среднее кол-во часов в игре: ' + srpl);
    document.getElementById("span2").innerHTML=document.getElementById("span2").innerHTML+ srpl;

    console.log(ob);
}