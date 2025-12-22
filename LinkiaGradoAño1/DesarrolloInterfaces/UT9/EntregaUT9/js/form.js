
document.addEventListener("DOMContentLoaded",function() { // cuaando pagina haya cargado
        alert("Documento Cargado");
    }
);

document.getElementById("registroForm").addEventListener('submit', function(e){
    e.preventDefault(); //bloquea comportamient habitual ya que lo vamos a cambiar
    let cuenta = 0;
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
        cuenta++;
        valido= false;
    }
    if(email.value.trim() === "") 
    {
        document.getElementById("errorEmail").textContent = "Email obligatorio";
        cuenta++;
        valido= false;
    }
    if(password.value.trim() === "") 
    {
        document.getElementById("errorPassword").textContent = "Password obligatorio";
        cuenta++;
        valido= false;
    }


    if(valido){
        document.getElementById("resultado").textContent = "Registro Exitoso";
        cuenta = 0;
        CrearAlerta("success", "Todo ha ido bien.");
        this.reset();
    }
    else if(cuenta < 3)
    {
        cuenta = 0;
        CrearAlerta("warning", "Hay algun campo vacio.");
    }
    else 
    {
        cuenta = 0;
        CrearAlerta("error", "Todos los campos vacios.");
    }
});


function CrearAlerta(tipoAlerta, mensaje) 
{
    const alertaExistente = document.querySelector('my-alert');
    if (alertaExistente) {
        alertaExistente.remove();
    }

    const alerta = document.createElement('my-alert');
    alerta.setAttribute('tipoDeAlerta', tipoAlerta);
    alerta.setAttribute('mensaje', mensaje);

    document.body.appendChild(alerta);
}