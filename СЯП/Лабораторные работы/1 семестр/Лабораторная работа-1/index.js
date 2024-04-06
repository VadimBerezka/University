const task1 = () => {
    alert("Вас приветствует учебный центр")
    let name = prompt("Введите имя")
    alert(`Добро пожаловать на наши курсы, ${name}`)
    let choice = confirm("Хотите стать Web-дизайнером?")
    if (choice) {
        alert("Учите стили CSS и JavaScript!")
    }
    else {
        alert("Упускаете время!")
    }
}

const task2 = () => {
    console.log(66 + 8)
    console.log("40" + "7")
    document.write(92 + "5", "<br>")
    document.write("23" + 5)
    alert("Результатом сложения строки и числа всегда будет строка")
}

const task3 = () => {
    let x = 25
    let y = 6

    let a = ((x ** y + (x / y)) / y ** y) * x
    let b = (x * x * y) / (x + y * x)

    let ostatok = a % b

    document.write("Значения одного выражения   ", a, "<br>")
    console.log("Значения одного выражения   ", a)

    document.write("Значения другого выражения  ", b, "<br>")
    console.log("Значения другого выражения  ", b)

    document.write("Остаток от деления  ", ostatok)
    console.log("Остаток от деления  ", ostatok)
}

const task4 = () => {
    const number = prompt('Введите любое число')
    if (!(number >= 100 && number <= 200 && number != 111 || number == 17)) {
        alert("Правильное значение")
    } else {
        alert("Неправильное значение")
    }
}

const task5 = () => {
    const a = prompt('Введите число А')
    const b = prompt('Введите число Б')


    /*
        if (a > b) {
            alert('А больше Б')
        }
        else if (a < b) {
            alert('А меньше Б')
        }

     */
    a > b ? alert('A больше') : alert('Б меньше')
}

const task6 = () => {
    let date = new Date()
    let day = date.getDay()

    switch (day) {

        case 0: alert('Воскресенье')
            break
        case 1: alert('Понедельник')
            break
        case 2: alert('Вторник')
            break
        case 3: alert('Среда')
            break
        case 4: alert('Четверг')
            break
        case 5: alert('Пятница')
            break
        case 6: alert('Суббота')
            break
        default:
            alert("Ошибка")
    }
}

function task7 () {
    const a = 0b1000101

    const b = 0o1631

    const c = 0x6a9
    document.write(a, "<br>", b, "<br>", c)
    console.log(a, b, c)
}

const task8 = () => {
    let a = prompt('Введите делимое')
    let b = prompt('Введите делитель')
    let result = a / b

    try {
        if (result === Infinity) {
            throw new Error("Ошибка: деление на ноль невозможно")
        }
        else {
            console.log("Результат деления:", result)
        }
    } catch (error) {
        throw new Error(error.message)
    }
}