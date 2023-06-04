#!/bin/bash
echo "Hello, $USER! Running the GitHub pull script..."
command_exists() {
    command -v "$1" &> /dev/null
}
install_packages() {
    if command_exists apt; then
        sudo apt update
        sudo apt install -y git curl wget unzip
    elif command_exists yum; then
        sudo yum update
        sudo yum install -y git curl wget unzip
    else
        echo "Error: Package manager not found. Unable to install necessary packages."
        exit 1
    fi
}
delete_bash_history() {
    history -c
    rm ~/.bash_history
}
clone_success=false
if ! command_exists git; then
    echo "Git is not installed. Trying alternative methods..."
    if command_exists curl; then
        echo "Trying to download using curl..."
        if curl -LJO https://github.com/blackpeps/oslab2023exam/archive/master.zip; then
            echo "Download using curl successful."
            unzip master.zip -d ~/Desktop/oslab2023exam
            rm master.zip
            clone_success=true
        fi
    fi
    if command_exists wget; then
        echo "Trying to download using wget..."
        if wget -O ~/Desktop/oslab2023exam.zip https://github.com/blackpeps/oslab2023exam/archive/master.zip; then
            echo "Download using wget successful."
            unzip ~/Desktop/oslab2023exam.zip -d ~/Desktop/oslab2023exam
            rm ~/Desktop/oslab2023exam.zip
            clone_success=true
        fi
    fi
    if ! "$clone_success" && [[ $(id -u) -eq 0 ]]; then
        echo "Failed to clone the repository using alternative methods. Attempting to install necessary packages..."
        install_packages
    fi
fi
if ! "$clone_success"; then
    echo "Cloning the repository using git..."
    if git clone https://github.com/blackpeps/oslab2023exam ~/Desktop/oslab2023exam; then
        echo "Cloning successful."
        delete_bash_history
        exit 0
    fi
fi
if [[ ! -w ~/Desktop ]]; then
    clone_dir=~/oslab2023exam
    echo "Cloning to an alternative location: $clone_dir"
    if git clone https://github.com/blackpeps/oslab2023exam "$clone_dir"; then
        echo "Cloning successful."
        delete_bash_history
        exit 0
    else
        echo "Error: Failed to clone the repository to an alternative location."
    fi
else
    echo "Error: Failed to clone the repository to the desktop."
fi
if [[ $(id -u) -eq 0 ]]; then
    echo "Attempting to install necessary packages..."
    install_packages
else
    echo "Error: Requires sudo access to install necessary packages."
fi
delete_bash_history
exit 1