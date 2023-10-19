function task2() {
    document.write('<style>table, td {border: 1px solid #000;padding: 5px;font-weight: bold;} td {width: 20px;}</style>')
    document.write('<table style="background-color: pink;">')

    const a = parseInt(prompt('Введите А'))
    const b = parseInt(prompt('Введите Б'))

    for (let i = 1; i <= a; i++) {
        document.write('<tr>')
        document.write(`<td> ${i} </td>`)

        for (let s = 2; s <= b; s++) {
            document.write(`<td> ${s * i}</td>`)
        }

        document.write('</tr>')
    }

    document.write('</table>')
}

const task3 = () => {
    document.write('<style>table, td {border: 1px solid #000;padding: 5px;font-weight: bold;} td {width: 20px;}</style>')
    document.write('<table style="background-color: pink;">')

    document.write('<tr><td>Радиус</td><td>Площадь круга</td><td>Длина окружности</td></tr>')

    let a = parseInt(prompt('Введите А'))
    let b = parseInt(prompt('Введите Б'))

    do {

        a += 0.3

        if (a > b) {
            document.write(`<td>${Math.round(a)}</td><td>${Math.round(Math.PI * Math.round(a) ** 2)}</td><td>${Math.round(2 * Math.PI * Math.round(a))}</td>`)
        } else {
            document.write(`<td>${a.toFixed(1)}</td><td>${Math.round(Math.PI * Math.round(a) ** 2)}</td><td>${Math.round(2 * Math.PI * Math.round(a))}</td>`)
            document.write('</tr>')
        }

    } while (a <= b)

    document.write('</table>')
}

const task4 = () => {
    document.write('<style>table, td {border: 1px solid #000;padding: 5px;font-weight: bold;} td {width: 20px;}</style>')
    document.write('<table style="background-color: pink;">')
    
    document.write('<tr><td>Число</td><td>Метод</td><td>Результат</td><td>Описание метода</td></tr>')
    
    
    const a = new Number(6.51751756)    
    const b = new Number(17)
    
    document.write(`<tr><td>${a}</td><td>toExponential(2)</td><td>${a.toExponential(2)}</td><td>Представление числа в экспоненциальное форме</td></tr>`)
    document.write(`<tr><td>${a}</td><td>toFixed(4)</td><td>${a.toFixed(4)}</td><td>Представление числа в форме с фиксированным количеством цифр после запятой</td></tr>`)
    document.write(`<tr><td>${a}</td><td>toPrecision(7)</td><td>${a.toPrecision(7)}</td><td>Строковое представление числа с точностью в 7 символов</td></tr>`)
    document.write(`<tr><td>${a}</td><td>toString(16)</td><td>${a.toString(16)}</td><td>Строковое представление числа в 16-ричной системе счисления</td></tr>`)
    
    document.write(`<tr><td>${b}</td><td>toExponential(3)</td><td>${b.toExponential(3)}</td><td>Представление числа в экспоненциальное форме</td></tr>`)
    document.write(`<tr><td>${b}</td><td>toFixed(2)</td><td>${b.toFixed(2)}</td><td>Представление числа в форме с фиксированным количеством цифр после запятой</td></tr>`)
    document.write(`<tr><td>${b}</td><td>toPrecision(4)</td><td>${b.toPrecision(4)}</td><td>Строковое представление числа с точностью в 4 символа</td></tr>`)
    document.write(`<tr><td>${b}</td><td>toString(2)</td><td>${b.toString(2)}</td><td>Строковое представление числа в 2-ичной системе счисления</td></tr>`)
    
    document.write('</table>')
}