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
