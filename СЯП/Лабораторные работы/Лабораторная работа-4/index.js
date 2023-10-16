const Gruppa = {
    student: [],
    sub_stud: function(name) {
        this.student = this.student.filter(el => el !== name)
    },
    add_stub: function(name) {
        this.student.push(name)
    }
}

const gr2 = Object.assign({}, Gruppa);


window.Gruppa = Gruppa
window.gr2 = gr2