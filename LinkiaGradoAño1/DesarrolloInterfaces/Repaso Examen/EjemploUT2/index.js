function saludar()
{
    let nombre = prompt("Como te llamas") //aqui no hay double...
    console.log("Hola " + nombre); // o alert
}
//Document es el DOM

let botonSaludar= document.getElementById("boton-saludar");
botonSaludar.addEventListener('click', function() {
    alert("Botón clicado");
});

document.addEventListener("DOMContentLoaded",function() { // cuaando pagina haya cargado
        alert("Documento Cargado");
    }
);

document.getElementById("registroForm").addEventListener('submit', function(e){
    e.preventDefault(); //bloquea comportamient habitual ya que lo vamos a cambiar
    let valido = true;
    const nombre = document.getElementById("nombre");
    const email = document.getElementById("correo");
    const password = document.getElementById("contraseña");
    document.getElementById("errorNombre").textContent =" "; //los vaciamos antes de cada validacion
    document.getElementById("errorEmail").textContent =" ";
    document.getElementById("errorPassword").textContent =" ";
    if(nombre.value.trim() === "")  //elimina espacios al inicio y final para que no pase un “espacio vacío”.
    {
        document.getElementById("errorNombre").textContent = "Nombre obligatorio";
        valido= false;
    }
    if(email.value.trim() === "") 
    {
        document.getElementById("errorEmail").textContent = "Email obligatorio";
        valido= false;
    }
    if(password.value.trim() === "") 
    {
        document.getElementById("errorPassword").textContent = "Password obligatorio";
        valido= false;
    }
    if(valido){
        document.getElementById("resultado").textContent = "Registro Exitoso";
        this.reset();
    }
});