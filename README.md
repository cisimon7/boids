[1]: https://team.inria.fr/imagine/files/2014/10/flocks-hers-and-schools.pdf
[2]: https://www.sfml-dev.org

# Boids

Boids is a program developed by Craig Reynolds in 1986, which simulates the flocking behaviour of birds. He published
this model in 1987 in the seminal paper ["Flocks, Herds, and Schools: A Distributed Behavioral Model"][1].

The motion of a flock of birds is an example of emergent behavior -- each bird is only making individual
decisions, yet the motion of the entire flock is fluid and synchronized. Somehow, organized group behavior is able
to emerge as the aggregate of the local actions of each individual animal.

Boids simulates this individual decision making with three rules:

 1. **Separation:** individuals try to avoid crowding their nearby flockmates
 2. **Alignment:** individuals steer towards the average heading of nearby flockmates
 3. **Cohesion:** individuals try to move towards the center of mass of nearby flockmates

This repository contains an implementation of the boids model in C++.

![Simulation Example](assets/simulation-example.gif)

## Implementation Details

This implementation uses a [k-d tree](https://en.wikipedia.org/wiki/K-d_tree) to increase efficiency. A k-d tree
partitions the boids in space so that when each boid is updated, we only consider the nearby boids rather than
iterating over all boids and incurring an O(n<sup>2</sup>) cost.

The implementation also uses OpenMP for some simple parallelization that leads to further speedups (and therefore the
ability to simulate a larger number of boids).

