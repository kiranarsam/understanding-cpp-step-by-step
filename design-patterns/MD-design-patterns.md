# Design Pattern
**Design patterns** are typical solutions to commonly occurring problems in software 
design. They are like pre-made blueprints that you can customize to solve a recurring 
design problem in your code.

You can’t just find a pattern and copy it into your program, the way you can with 
off-the-shelf functions or libraries. The pattern is not a specific piece of code, 
but a general concept for solving a particular problem. You can follow the pattern
details and implement a solution that suits the realities of your own program.

Patterns are often confused with algorithms, because both concepts describe typical 
solutions to some known problems. While an algorithm always defines a clear set of 
actions that can achieve some goal, a pattern is a more high-level description of a 
solution. The code of the same pattern applied to two different programs may be 
different.

# What does the pattern consist of?
* **Intent** of the pattern briefly describes both the problem and the solution.
* **Motivation** further explains the problem and the solution the pattern makes possible.
* **Structure** of classes shows each part of the pattern and how they are related.
* **Code example** in one of the popular programming languages makes it easier to grasp the idea behind the pattern.

Some pattern catalogs list other useful details, such as applicability of the 
pattern, implementation steps and relations with other patterns.

# Classification of patterns
Design patterns differ by their complexity, level of detail and scale of 
applicability to the entire system being designed.

The most basic and low-level patterns are often called idioms. They usually apply 
only to a single programming language.

The most universal and high-level patterns are  architectural patterns. Developers 
can implement these patterns in virtually any language. Unlike other patterns, they 
can be used to design the architecture of an entire application.

In addition, all patterns can be categorized by their intent, or purpose. 

1. **Creational patterns** provide object creation mechanisms that increase flexibility and reuse of existing code.
    * **Factory Method**
        * Provides an interface for creating objects in a superclass, but allows 
        subclasses to alter the type of objects that will created.
    * **Abstract Factory**
        * Lets you produce families of related objects without specifying their 
        concrete classes.
    * **Builder**
        * Lets you construct complex objects step by step. The pattern allows you 
        to produce different types and representations of an object using the same 
        construction code.
    * **Prototype**
        * Lets you copy existing object without making your code dependent on their classes.
    * **Singleton**
        * Lets you ensure that a class has only one instance, while providing a 
        global access point to this instance.

1. **Structural patterns** explain how to assemble objects and classes into larger structures, while keeping the structures flexible and efficient.
    * **Adapter**
    * **Bridge**
    * **Composite**
    * **Decorator**
    * **Facade**
    * **Flyweight**
    * **Proxy**

1. **Behavioral patterns** take care of effective communication and the assignment of responsibilities between objects.
    * **Chain of Responsibility**
    * **Command**
    * **Iterator**
    * **Mediator**
    * **Memento**
    * **Observer**
    * **State**
    * **Strategy**
    * **Template Method**
    * **Visitor**

