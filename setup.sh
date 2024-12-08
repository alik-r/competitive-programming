#!/bin/bash

# Update and install g++
echo "Updating package list and installing g++..."
sudo apt update && sudo apt install -y g++

# Append configuration to .vimrc
echo "Appending configuration to .vimrc..."
cat <<EOL >> ~/.vimrc

" Custom configuration added by setup script
filetype detect
filetype indent on
syntax enable

set nocompatible
set exrc
set mouse=a
set tabstop=4
set shiftwidth=4
set smarttab
set smartindent
set cindent
set number 
set relativenumber
set nowrap
set autowrite
set autoread
set autoindent
set clipboard=unnamedplus

" Map F5 to compile the code
map <F5> :<C-U>w<CR>:!g++ -O2 -std=c++17 -Wall -Wextra -Wno-unused-result %:r.cpp -o %:r<CR>

" Map F9 to run the compiled code with time
map <F9> :!time ./%:r<CR>
EOL

# Create a directory named "dsa"
echo "Creating directory 'dsa'..."
mkdir -p ~/dsa

# Create min.cpp file in the "dsa" directory
echo "Creating min.cpp file..."
cat <<EOL > ~/dsa/min.cpp
#include "bits/stdc++.h"
using namespace std;

using ll = long long; 
using ull = unsigned long long;
using ld = long double;

void setIO(string name = "") {
	cin.tie(nullptr)->sync_with_stdio(false); 
	if ((int)name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main() {
	setIO();
}
EOL

echo "Setup complete! g++ installed, .vimrc updated, and 'dsa/min.cpp' created."
