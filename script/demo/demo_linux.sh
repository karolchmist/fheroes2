#!/bin/bash

mkdir demo
cd demo
wget https://archive.org/download/HeroesofMightandMagicIITheSuccessionWars_1020/h2demo.zip
unzip h2demo.zip
rm h2demo.zip

DATA_DIR=${XDG_DATA_HOME:-$HOME/.local/share}/fheroes2
mkdir -p "$DATA_DIR"

cp -r ./DATA "$DATA_DIR/data"
cp -r ./MAPS "$DATA_DIR/maps"
