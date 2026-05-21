class MyButton extends HTMLElement//HTMLELement es lq ue tiene todo
{ 
    constructor() { //
        super(); //inicializa elemetnos del padre
        const color = this.getAttribute('color') || 'red'; //pilla atributo del paadre
        const nombre = this.getAttribute('nombre');
        const shadow = this.attachShadow({mode: 'open'});
        const button = document.createElement('button');//va al dom y le crea elemento button
        button.textContent = this.textContent; //contenido del padre

        const style = document.createElement('style');
        style.textContent = `
            button {
                background-color: ${color};
                color: white; /* color texto */
                border: none;
                padding: 10px 20px;
                border-radius: 8px;
                cursor: pointer;
                font-size: 16px;
                transition: background-color 0.3s;
            }

            button:hover {
                background-color: #4338ca;
            }
        `; // aal pasar por encima le cambia el background

        shadow.appendChild(style); //le mete el estilo y el boton
        shadow.appendChild(button);

        button.addEventListener('click', () => {
            alert(`Has hecho click en "${button.textContent}, ${nombre}"`);
        });
    }
}

customElements.define('my-button', MyButton); //añadimos