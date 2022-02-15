# EVOLUTION OF COOPERATION BEHAVIORS IN A SWARM OF ADAPTIVE BOIDS

The flocking behavior of swarms of birds can be modelled by creating a swarm of artificial births (boids) which react to
observations by using simple control rules that increase cohesion, alignment and separation. Research in swarm robotics
is attempting to design swarms which can perform additional functions such as coordinately exploring an unknown area to
identify people to be rescued.

In this project we will evolve large swarms of boids for the ability to stay away from moving predators. Each boid is
provided with a camera from which it can extract the relative position and orientation of nearby boids and the relative
positions of nearby obstacles. More over each boid will be provided with a speaker used to emit sounds and a microphone
used to detect the sound signals produced by nearby boids. The neural network brain of boids will be adapted by using
the OpenAI-ES evolutionary algorithm or the PPO reinforcement learning algorithm. The boids can be simulated by adapting
the C++ library available from  

https://github.com/rystrauss/boids.

The scientific objective of this project is to verify whether evolving boids can develop an ability to coordinate and
cooperate to avoid long distant dangers and eventually an ability to monitor a large space region that enables them to
identify dangers as quickly as possible.

General Difficulty level:		    Medium
Programming effort:			        Medium (C++ required)
Simulation data to be collected: 	Low
Data analysis effort: 			    Low
Adaptive Algorithm:			        Evolutionary (OpenAI-ES) or Reinforcement learning (PPO)
