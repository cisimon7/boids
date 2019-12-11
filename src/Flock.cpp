//
// Created by Ryan Strauss on 12/10/19.
//

#include "Flock.h"

Flock::Flock() = default;

Flock::Flock(const Flock &other) {
    for (const Boid *b : other.boids) boids.push_back(new Boid{*b});
}

Flock::~Flock() {
    for (Boid *b : boids) delete b;
}

Boid *Flock::operator[](int i) const {
    return boids[i];
}

void Flock::add(Boid *boid) {
    boids.emplace_back(boid);
}

void Flock::update() {

}

int Flock::size() {
    return boids.size();
}
