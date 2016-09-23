#!/bin/bash

for i in $(seq 2 0.01 6.03)
do
for j in $(seq 2 0.01 6.03)
do
        ./alter_neutrinos.x $i $j
done
done
