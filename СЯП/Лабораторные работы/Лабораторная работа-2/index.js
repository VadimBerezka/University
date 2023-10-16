const task2 = () => {
    const table = document.createElement('table');

    const a = parseInt(prompt('Введите А'))
    const b = parseInt(prompt('Введите Б'))

    for (let i = 1; i <= a; i++) {
        const tr = document.createElement('tr');
        const td = document.createElement('td');
        td.append(i)

        tr.append(td)
        for (let s = 2; s <= b; s++) {
            const tdCell = document.createElement('td');
            tdCell.append(s * i)
            tr.append(tdCell)
        }
        table.append(tr)

    }
    document.body.append(table)
}

const task3 = () => {
    document.write('<style>table, td {border: 1px solid #000;padding: 5px;font-weight: bold;} td {width: 20px;}</style>')
    document.write('<table style="background-color: purple;">')

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
