filetype detect
set nocompatible
set exrc
set mouse=a
set tabstop=4
set shiftwidth=4
set smarttab
set smartindent
set cindent
set number
set nowrap
set autowrite
set autoread
set autoindent

map <F5> :<C-U>!g++ -O2 -std=c++17 -Wall -Wextra -Wno-unused-result %:r.cpp -o %:r<CR>

" For Neovim: 
" vim.keymap.set('n', '<F5>', function()
"   vim.cmd(":!g++ -O2 -std=c++17 -Wall -Wextra -Wno-unused-result %:r.cpp -o %:r")
" end, { desc = 'Compile C++ code' })

" See also https://github.com/nvim-lua/kickstart.nvim
