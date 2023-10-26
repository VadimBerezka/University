const task1 = () => {
    const s = 17
    const n = 5
    const v12 = 2006

    const raz = 6 - Math.PI ** 2 + 3 * Math.E ** 8
    const dva = 2 * Math.cos(4) + Math.cos(12) + 8 - Math.E ** 3
    const tri = 3 * Math.sin(9) + Math.log10(5) + s
    const cheture = 2 * Math.tan(5) + 6 - n + v12
    const arr = new Array(raz, dva, tri, cheture)
    console.log('Array: ', arr)

    let max = Math.max(...arr)
    let maxIn = arr.indexOf(max)
    let min = Math.min(...arr)    
    let minIn = arr.indexOf(min)
    
    console.log('Max number: ', max)
    console.log('Max Index: ', maxIn)
    console.log('Min number: ', min)
    console.log('Min Index: ', minIn)
}

const task3 = () => {
    const arr1 = Array.from('Vadimka')
    const arr2 = Array.of(1, 2, 3)
    console.log(arr1, arr2)
}

const task4 = () => {
    v = new Array();
    v[0] = "pow";
    v[1] = "pop";
    v[2] = "push";
    v[3] = "shift";
    v[4] = "round";
    v[5] = "floor";
    v[6] = "slice";
    v[7] = "sort";

    arr = new Array();
    arr[0] = "pop";
    arr[1] = "push";
    arr[2] = "shift";
    arr[3] = "slice";
    arr[4] = "sort";
    arr.unshift("concat");

    mat = new Array();
    mat[0] = "pow";
    mat[1] = "round";
    mat[2] = "floor";
    mat.push("min");

    console.log('Исходный массив: ', v)
    console.log('Первый массив: ', arr, 'Длина первого массива: ', arr.length)
    console.log('Второй массив: ', mat, 'Длина второго массива: ', mat.length)
    
}

const task5 = () => {
    const str = new String('Берёзка Вадим Сергеевич')
    const str1 = str.toUpperCase()
    const str2 = str.toLowerCase()
    const str3 = str1.concat(str2)
    const str4 = str.replace(str,'Б.В.С.')

    console.log('Длина строки: ', str.length)
    console.log('Исходная строка: ', str)
    console.log('Верхний регистр: ', str1)
    console.log('Нижний регистр: ', str2)
    console.log('Соединение: ', str3)
    console.log('ФИО: ', str4)
}

const task6 = () => {
    const date = new Date;
    document.write('<table style="background-color: pink;">')

    document.write(`<tr><td>Год</td><td>${date.getFullYear()}</td></tr>`)
    document.write(`<tr><td>Месяц</td><td>${date.getMonth()+1}</td></tr>`)
    document.write(`<tr><td>День</td><td>${date.getDate()}</td></tr>`)
    document.write(`<tr><td>Час</td><td>${date.getHours()}</td></tr>`)
    document.write(`<tr><td>Минуты</td><td>${date.getMinutes()}</td></tr>`)
    document.write(`<tr><td>Секунды</td><td>${date.getSeconds()}</td></tr>`)

    document.write('</table>')
}