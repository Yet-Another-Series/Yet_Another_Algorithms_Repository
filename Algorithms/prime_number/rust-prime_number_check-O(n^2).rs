#![windows_subsystem = "windows"]
use std::io;

fn main(){
    let mut range = String::new();
    println!("Enter the Number you want the list of Prime Numbers upto:- ");
    io::stdin().read_line(&mut range).expect("Bad Input");
    
    let range: u32 = match range.trim().parse(){
        Ok(num)=>num,
        Err(_)=>0,
    };
    
    let mut counter:u32 = 2;
    
    while counter < range {
        if prime_check(counter) {
            print!(" {}",counter);
            counter+=1;
        } else {
            counter+=1;
        };
    };
    
}

fn prime_check(x:u32) -> bool{

    let fact: u32 = if x%2 != 0{
        (x+1)/2
    } else {
        x/2
    };
    
    let mut count: u32 = 2;
    while count <= fact {
        if x%count == 0{
            return false;
        } else {
            count+=1;
        }
    };
    return true;
}


