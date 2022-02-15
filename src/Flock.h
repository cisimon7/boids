//
// Created by Ryan Strauss on 12/10/19.
//

#ifndef BOIDS_FLOCK_H
#define BOIDS_FLOCK_H

#include <vector>
#include "Boid.h"

/* Total number of boids on display make the boid in a KDTree structure. */
class Flock {
private:
    std::vector<Boid> boids; /* All boids. */

public:

    Flock();

    Flock(const Flock &other);

    ~Flock();

    /* Returns boid at depth i of the KDTree. */
    Boid operator[](int i) const;

    /* Inserts new boid into the KDTree. */
    void add(const Boid &boid);

    void clear();

    void update(float window_width, float window_height, int num_threads = -1);

    int size() const;

};


#endif //BOIDS_FLOCK_H
