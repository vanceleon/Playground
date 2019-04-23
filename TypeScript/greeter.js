// function greeter(person: string) {
//     return "Hello, " + person;
// }
// let user = "Vance Leon";
// document.body.innerHTML = greeter(user);
// interface Person {
//     firstName: string;
//     lastName: string;
// }
// function greeter(person: Person) {
//     return "Hello, " + person.firstName + " " + person.lastName;
// }
// let user = {firstName: "Jane", lastName: "User"};
// document.body.innerHTML = greeter(user);
// CLass Implementation
var Student = /** @class */ (function () {
    function Student(firstName, middleInitial, lastName) {
        this.firstName = firstName;
        this.middleInitial = middleInitial;
        this.lastName = lastName;
        this.fullName = firstName + " " + middleInitial + " " + lastName;
    }
    return Student;
}());
function greeter(person) {
    return "Hello, " + person.firstName + " " + person.lastName;
}
