const task1 = () => {
    function Gruppa() {
        this.students = [];
        this.add_stud = function (name) {
            this.students.push(name)
        }
        this.sub_stud = function (num) {
            this.students.splice(0, num)
        }
    }

    var gr2 = new Gruppa()
    gr2.add_stud("Карианна")
    gr2.add_stud("Вадим")
    gr2.add_stud("Кирилл")
    gr2.add_stud("Марина")
    gr2.add_stud("Екатерина")
    gr2.sub_stud(3)

    var gr3 = new Gruppa()
    gr3.add_stud("Полина")
    gr3.add_stud("Алексей")
    gr3.add_stud("Никита")
    gr3.add_stud("Станислав")
    gr3.add_stud("Марина")
    gr3.sub_stud(5)

    var gr4 = new Gruppa()
    gr4.add_stud("Полина")
    gr4.add_stud("Максим")
    gr4.add_stud("Алексанадр")
    gr4.add_stud("Глеб")
    gr4.add_stud("Анна")

    document.write("Количество студентов в gr2: " + gr2.students.length + "<br>")
    document.write("Количество студентов в gr3: " + gr3.students.length + "<br>")
    document.write("Количество студентов в gr4: " + gr4.students.length + "<br>")
}

const task2 = () => {
    class Student {
        constructor (name, surname, physics, math, informatics, age) {
        this.name = name
        this.surname = surname
        this.physics = physics
        this.math = math
        this.informatics = informatics
        this.age = age

        this.alertN_S = function () {
            alert(this.name + " " + this.surname)
        }

        this.average_score = function () {
            var average = (this.physics + this.math + this.informatics) / 3
            document.write("Имя: " + this.name + "<br>" + "Фамилия: " + this.surname + "<br>" + " Средний балл: " + average + "<br>" + " Математика: " + this.math + "<br>" + " Физика: " + this.physics + "<br>" + " Информатика: " + this.informatics + "<br>" + " Возраст: " + this.age + "<br>"+ "<br>")
        }
    }
}
    Student.prototype.changename = function(newname) {
    this.name = newname
    }

    /*
    С помощью свойства prototype можно добавлять новые свойства и
методы к конструкторам объектов. Добавленные к конструктору свойства и
методы будут также добавлены ко всем объектам, которые были созданы
данным конструктором. Например, Gruppa.prototype.kurs=this.kurs.
    */

    let student1 = new Student('', "Берёзка", 10, 10, 10, 17)
    let student2 = new Student('', "Юрасов", 8, 7, 9, 18)
    let student3 = new Student('', "Чередник", 2, 3, 4, 18)

    student1.changename('Вадим')
    student2.changename('Вадим')
    student3.changename('Вадим')



    student1.alertN_S()
    student1.average_score()

    student2.alertN_S()
    student2.average_score()

    student3.alertN_S()
    student3.average_score()
}



const task3 = () => {
    
    let massiv = [1, 2 ,3 ,4 ,5 ,6]
    document.write('Исходный массив ' + massiv + '<br>')
    delete massiv[4]
    document.write('Массив с удалённым элементом ' + massiv + '<br>')
    
    console.log('In')
    console.log(2 in massiv)


    function Student(name, surname, physics, math, informatics, age) {
        this.name = name
        this.surname = surname
        this.physics = physics
        this.math = math
        this.informatics = informatics
        this.age = age
    }
    
    const student1 = new Student("Вадим", "Берёзка", 10, 10, 10, 17)
    console.log('name' in student1)



    function Gruppa(gruppa , podgruppa, nomer) {
        this.gruppa = gruppa
        this.podgruppa = podgruppa
        this.nomer = nomer
        
    }
    let gr1 = new Gruppa(3, 1, 2)
    console.log('nomer' in Gruppa)

    

    console.log('Instanceof')
    console.log(massiv instanceof Array )
    console.log(massiv instanceof String)
    console.log(massiv instanceof Object )
    console.log(student1 instanceof Array )
    console.log(student1 instanceof String )
    console.log(student1 instanceof Object )
    console.log(gr1 instanceof Array)
    console.log(gr1 instanceof String)
    console.log(gr1 instanceof Object)

    console.log('TypeOf')
    function fun5() {
        return 5
    }
    console.log(typeof Gruppa)
    console.log(typeof Student)
    console.log(typeof fun5())
    console.log(typeof Gruppa.name)
    console.log(typeof Gruppa.surname)
    console.log(typeof Gruppa.phisycs)
    console.log(typeof Student.math)
    console.log(typeof Student.informatics)
    console.log(typeof Student.age)
    console.log(typeof Student.gruppa)
    console.log(typeof Student.podgruppa)
    console.log(typeof Student.nomer)
}