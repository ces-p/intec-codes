use std::io;

fn main(){
    let mut nombre = String::new();
    println!("escribe tu nombre");

    match io::stdin().read_line(&mut nombre){
        Ok(_) => {
            if nombre.trim().is_empty(){
                panic!("return code 100")
            }else{
                println!("Hola {}", nombre);
            }
            
        }, Err(e) => println!("Failed because of {}", e)
    }
}
