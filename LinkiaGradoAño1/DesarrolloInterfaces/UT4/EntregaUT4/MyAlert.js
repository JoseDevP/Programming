class MyAlert extends HTMLElement{
    constructor(){
        super();
        this.attachShadow({ mode: 'open' });
        this.tipoDeAlerta = this.getAttribute("tipoDeAlerta") || "informar";
        this.mensaje = this.getAttribute("mensaje") || "No hay mensaje"; 
    }

    connectedCallback()
    {
        this.Renderizar(); //llamo al metodo render
    }

    Renderizar()
    {
        const colores = { //creo una listaa con los colores
          success: '#19f120ff',
          error: '#f81100ff',
          warning: '#c48323ff'
        };
        
        //shadow creado antes con attachshaadow
        this.shadowRoot.innerHTML = `
          <style>
            .alerta {
              position: fixed; /* se mantiene en la pantalla */
              top: 50%; /* centro vertical */
              left: 50%; /* centro horizontal */
              transform: translate(-50%, -50%); /* ajuste perfecto para centrar */
              width: 300px; /* tamaño fijo para el cuadro */
              padding: 20px; 
              border-radius: 8px; /* bordes ligeramente redondeados */
              background-color: ${colores[this.tipoDeAlerta]};
              color: white;
              display: flex;
              flex-direction: column; /* vertical: mensaje arriba, botón abajo */
              align-items: center;
              font-family: sans-serif;
              text-align: center;
              box-shadow: 0 4px 12px rgba(0,0,0,0.3); /* sombra para destacar */
              z-index: 9999; /* asegurarse que esté encima de todo */
            }
            button {
              margin-top: 15px;
              padding: 8px 16px;
              background: white;
              color: ${colores[this.tipoDeAlerta]};
              border: none;
              border-radius: 4px;
              font-weight: bold;
              cursor: pointer;
            }
          </style>

          <div class="alerta">
            <span>${this.mensaje}</span>
            <button id="cerrar">Cerrar</button>
          </div>
        `; //creo un div donde pondre el mensaje de laa alerta y un boton para cerrar

        this.shadowRoot.querySelector('#cerrar').addEventListener('click', () => {
            this.remove(); //elimino el componente del DOM
        });
       
    }
}

customElements.define('my-alert', MyAlert); //añado a customelements