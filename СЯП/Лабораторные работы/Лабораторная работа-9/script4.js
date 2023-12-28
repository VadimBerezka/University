function drawChart() {
    let size = 3

    let color = document.getElementById('color').value
    let choices = document.getElementsByName('chart')
    let choice
    for (i = 0; i < choices.length; i++) {
        if (choices[i].checked) {
            choice = choices[i].value
            break
        }
    }
    console.log(choice)

    let x1 = 0
    let x2 = 1
    let y1
    let y2

    let nmax = calculateNMax(choice)

    for (i = 1; i <= nmax; i++) {
        y1 = calculateY(choice, x1)
        y2 = calculateY(choice, x2)
        n = Math.ceil(Math.abs((y2 - y1)) / 2)
        for (j = 1; j <= n; j++) {
            if (y1 <= y2) {
                y = y1 + j - 1
            }
            else {
                y = y1 - j - 1;
            }
            drawPoint(color, size, x1, y);
        }
        for (j = n + 1; j <= y2 - y1 + 1; j++) {
            if (y1 <= y2) {
                y = y1 + j - 1;
            }
            else {
                y = y1 - j - 1;
            }
            drawPoint(color, size, x2, y);
        }
        x1++;
        x2++;
    }

}

function calculateNMax(choice) {
    if (choice === 'sin') {
        return 1000;
    }
    if (choice === 'cos') {
        return 200;
    }
    if (choice === 'x^2') {
        return 200;
    }
    if (choice === 'x^3') {
        return 10;
    }
    return 0;
}

function calculateY(choice, x) {
    if (choice === 'sin') {
        return 50 * Math.sin(x / 5) + 60;
    }
    if (choice === 'cos') {
        return 50 * Math.cos(x / 5) + 60;
    }
    if (choice === 'x^2') {
        return Math.pow(x, 2);
    }
    if (choice === 'x^3') {
        return Math.pow(x, 3);
    }
    return 0;
}

function drawPoint(color, size, x, y) {
    point = '<img src="images/' + color + '.png" style="position: absolute; width: ' + size + 'px; left: ' + x + 'px; top: ' + y + 'px;">';
    document.write(point);
}
