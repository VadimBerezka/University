const task1 = () => {
    const s = 17
    const n = 5
    const v12 = 2006

    const raz = 6 - Math.PI ** 2 + 3 * Math.E ** 8
    const dva = 2 * Math.cos(4) + Math.cos(12) + 8 - Math.E ** 3
    const tri = 3 * Math.sin(9) + Math.log10(5) + s
    const cheture = 2 * Math.tan(5) + 6 - n + v12
    const arr = new Array(raz, dva, tri, cheture)
    console.log('Массив: ', arr)

    let max = Math.max(...arr)
    let maxIn = arr.indexOf(max)
    let min = Math.min(...arr)    
    let minIn = arr.indexOf(min)
    
    console.log('Максимальный элемент массива: ', max)
    console.log('Индекс максимального элемента массива: ', maxIn)
    console.log('Минимальный элемент массива: ', min)
    console.log('Идекс минимального элемента массива: ', minIn)
}

const task3 = () => {
    const arr1 = Array.from('Vadimka')
    const arr2 = Array.of(1, 2, 3)
    console.log(arr1, arr2)
}

const task4 = () => {
/*     massivchik = new Array();
    massivchik[0] = "pow";
    massivchik[1] = "pop";
    massivchik[2] = "push";
    massivchik[3] = "shift";
    massivchik[4] = "round";
    massivchik[5] = "floor";
    massivchik[6] = "slice";
    massivchik[7] = "sort";

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

    console.log('Исходный массив: ', massivchik, 'Длина исходного массива', massivchik.length)
    console.log('Первый массив: ', arr, 'Длина первого массива: ', arr.length)
    console.log('Второй массив: ', mat, 'Длина второго массива: ', mat.length) */

    let arr_met = [Math.pow, Array().pop, Array().push, Array().shift, Math.round, Math.floor, Array().slice, Array().sort]; 
    let arr_Array_met = []; 
    let arr_Math_met = []; 
     
    for (let i = 0; i < arr_met.length; i++ ){ 
        if (Object.hasOwn(Math, arr_met[i].name)){ 
            arr_Math_met.push(arr_met[i]) 
        }  
        else { 
            arr_Array_met.push(arr_met[i]) 
        } 
    }   
      
    arr_Array_met.push(Array().concat); 
    arr_Math_met.unshift(Math.min); 
    
    console.log(arr_met); 
    console.log(arr_met.length); 
    
    console.log(arr_Math_met); 
    console.log(arr_Math_met.length); 
    
    console.log(arr_Array_met); 
    console.log(arr_Array_met.length);
    
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
    document.write('<style>td {border: 1px solid #f00;}</style>')
    
    document.write(`<tr><td>Год</td><td>${date.getFullYear()}</td></tr>`)
    document.write(`<tr><td>Месяц</td><td>${date.getMonth()+1}</td></tr>`)
    document.write(`<tr><td>День</td><td>${date.getDate()}</td></tr>`)
    document.write(`<tr><td>Час</td><td>${date.getHours()}</td></tr>`)
    document.write(`<tr><td>Минуты</td><td>${date.getMinutes()}</td></tr>`)
    document.write(`<tr><td>Секунды</td><td>${date.getSeconds()}</td></tr>`)

    document.write('</table>')
}