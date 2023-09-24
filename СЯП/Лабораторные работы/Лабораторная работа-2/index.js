const task2 = () => {
    document.write('<style>table, td {border: 1px solid #000;padding: 5px;font-weight: bold;} td {width: 20px;}</style>')
    document.write('<table>')

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
