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
class Student {
    fullName: string;
    constructor(public firstName: string, public middleInitial: string, public lastName: string) {
        this.fullName = firstName + " " + middleInitial + " " + lastName;
    }
}

interface Person {
    firstName: string;
    lastName: string;

}

function greeter(person: Person) {
    return "Hello, " + person.firstName + " " + person.lastName;
}