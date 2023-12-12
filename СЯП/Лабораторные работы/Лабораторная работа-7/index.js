const sub = () => {

    let fam = document.forms.data.fam.value
    let spec = document.forms.data.sel.value
    let kurs = document.forms.data.kurs.value
    var mass = []
    let subjects = document.querySelectorAll(".check")
    let text = document.getElementById("textarea").value

    for (var i = 0; i < subjects.length; i++) {
        if (subjects[i].checked) {
            mass.push(subjects[i].value)
        }
    }

    document.write(`<p>`+ text +`</p>`)
    document.write(' Студент ' + fam + ' специальность ' + spec + ' курс ' + kurs + ' должен сдавать следующие предметы: ')
    let ul = document.createElement("ul")
    
    for (let i = 0; i < mass.length; i++) {
        let tab = ul.appendChild(document.createElement("li")).innerHTML = subjects[i].value
        document.body.append(ul)
    }
}