# Monte Carlo Random Walk — RNG Bias Visualization

This project simulates a random walker using two different random number generators to show how biased randomness creates visible patterns.

It is inspired by how casino inspectors test roulette wheels and slot-machine RNGs for hidden bias using Monte Carlo methods.

Two C++ programs are included:

* good_rng.cpp - uses std::mt19937 (high-quality randomness)
* bad_rng.cpp - uses a simple LCG with poor seed behaviour (biased, predictable)

Both programs simulate thousands of walkers and record only their final landing positions, producing a PPM image.

---

## Why This Matters (Casino Analogy)

Roulette wheels can become biased due to:

* uneven wheel surface
* worn bearings
* slight tilt
* non-uniform or sticky pockets
* friction differences
* rotor-speed fluctuations
* lubrication issues
* micro-imperfections that make certain pockets more likely

Each walker acts like one roulette ball.
Each step represents a bounce.
The final position represents the pocket the ball would land in.

A fair RNG produces a smooth, circular cloud of endpoints.
A biased RNG produces clusters, streaks, “islands,” and repeating structures. It resembles a fractal when keenly observed.

These shapes visually reveal the hidden bias — the same way real inspectors detect broken roulette wheels and flawed slot-machine algorithms.

---

## File Structure

```
src/
    good_rng.cpp
    bad_rng.cpp

out/
    good_walk.ppm
    bad_walk.ppm
```

---

## Build and Run

### Compile good RNG  
```
g++ -O2 good_rng.cpp -o good  
./good
```  
### Compile bad RNG  
```
g++ -O2 bad_rng.cpp -o bad  
./bad
```
---

## Viewing the Images

View the PPM in any viewer or convert using ImageMagick:
```
magick good_walk.ppm good.png
```
```
magick bad_walk.ppm bad.png
```
---

## What You Should Notice

### good_rng

* smooth, even distribution
* no visible structure
* randomness behaves as expected

### bad_rng

* clusters and repeating patches
* visible islands / hotspots
* biased behaviour created by the weak RNG

The shape of the cloud tells you everything about the underlying randomness.

---

## Notes

* The walkers always start at the center to make the comparison fair.
* The simulation only marks **endpoints**, not the full path, to mimic roulette-style“final pocket”outcomes.
* The bad RNG uses a classic LCG with weak low bits, this reproduces the exact kind of flaws seen in outdated or poorly designed random systems.
* Even tiny imperfections (in RNGs or physical machines) become obvious when repeated thousands of times, patterns always expose bias.
* This project is a simplified demonstration of how Monte Carlo testing is used in real-world auditing, simulation, and casino quality control.

---
