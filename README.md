# Antmazing

An evolutionary ant simulation. The plan is to implement the following steps

* ✓ A project setup that allows for separate compilation of app and unit test binaries
* ✓ A SFML graphics window for display of simulation content
* ✓ A simple model for ants to wander around in the world and leave behind trails they can sense and follow
* An artificial intelligence to process a local trail to follow it
* Some kind of reward in case a trail leads to some kind of food
* A negative marker to mark unsuccessful trails
* the ability for an ant to decide if a trail is (or isn't) worth it and to modify their markers correspondingly
* An evolutionary selection process for ant AIs through multiple generations
* An oscillating selection pressure, via extinction and food surplus events, favouring successful or divers builds of ants