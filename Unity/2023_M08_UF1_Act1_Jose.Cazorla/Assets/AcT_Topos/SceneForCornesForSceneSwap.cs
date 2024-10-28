using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem.EnhancedTouch;

using Touch = UnityEngine.InputSystem.EnhancedTouch.Touch;
using UnityEngine.SceneManagement;

public class SceneForCornesForSceneSwap : MonoBehaviour
{
    [Header("Logic")] //Cabeceras
    [SerializeField] string sceneToLoad;

    [Header("Debug")]
    [SerializeField] bool debugSwapScene;

    float timePressingAllFourCorners;

    //Hayq ue habilitar cualquier control del input system
    private void OnEnable()
    {
        EnhancedTouchSupport.Enable();
    }

    private void OnDisable()
    {
        EnhancedTouchSupport.Disable();
    }

    private void OnValidate() //Se llama cada vez que cambia un valor
    {
        if (debugSwapScene)
        {
            debugSwapScene = false;
            Debug.Log("Hola chicos!");
            LoadNextScene();
        }



    }
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        int touchesInAnyCorner = 0;
        int touchesInTopLeftCorner = 0;
        int touchesInTopRightCorner = 0;
        int touchesInBottomLeftCorner = 0;
        int touchesInBottomRightCorner = 0;

        foreach (Touch t in Touch.activeTouches)//recorrer todo dentro de Touch.activeTouches  realizamos una accion
        {
            Vector2 position = t.screenPosition;
            Vector2 normalizedPosition = position; 
            normalizedPosition.x /= Screen.width; 
            normalizedPosition.y /= Screen.height; //La ponemos de 0 a 1

            //Control r m
            CheckTopLeftCorner(ref touchesInAnyCorner, ref touchesInTopLeftCorner, position);
            CheckTopRightCorner(ref touchesInAnyCorner, ref touchesInTopRightCorner, position);
            CheckBottomLeftCorner(ref touchesInAnyCorner, ref touchesInBottomLeftCorner, position);
            CheckBottomRightCorner(ref touchesInAnyCorner, ref touchesInBottomRightCorner, position);

            
        }
        CheckLoadNextScene(touchesInTopLeftCorner, touchesInTopRightCorner, touchesInBottomLeftCorner, touchesInBottomRightCorner);
        //Esto se podria hacer asi tambiem
        //for(int i=0;<Touch.activeTouches.Count;i++) 
        //{
        //    Touch t = Touch.activeTouches[i];
        //    Debug.Log(t.screenPosition);
        //}

    }

    private static void CheckBottomRightCorner(ref int touchesInAnyCorner, ref int touchesInBottomRightCorner, Vector2 position)
    {
        if ((position.x > 0.9f) && (position.y < 0.1f))
        {
            touchesInBottomRightCorner++;
            touchesInAnyCorner++;
        }
    }

    private static void CheckBottomLeftCorner(ref int touchesInAnyCorner, ref int touchesInBottomLeftCorner, Vector2 position)
    {
        if ((position.x < 0.1f) && (position.y < 0.1f))
        {
            touchesInBottomLeftCorner++;
            touchesInAnyCorner++;
        }
    }

    private static void CheckTopRightCorner(ref int touchesInAnyCorner, ref int touchesInTopRightCorner, Vector2 position)
    {
        if ((position.x > 0.9f) && (position.y > 0.9f))
        {
            touchesInTopRightCorner++;
            touchesInAnyCorner++;
        }
    }

    private static void CheckTopLeftCorner(ref int touchesInAnyCorner, ref int touchesInTopLeftCorner, Vector2 position)
    {
        if ((position.x < 0.1f) && (position.y > 0.9f))
        {
            touchesInTopLeftCorner++;
            touchesInAnyCorner++;
        }
    }

    private void CheckLoadNextScene(int touchesInTopLeftCorner, int touchesInTopRightCorner, int touchesInBottomLeftCorner, int touchesInBottomRightCorner)
    {
        if ((touchesInTopLeftCorner >= 1) && (touchesInTopRightCorner >= 1) && (touchesInBottomLeftCorner >= 1) && (touchesInBottomRightCorner >= 1))
        {
            timePressingAllFourCorners += Time.deltaTime;
            if(timePressingAllFourCorners>3f)
            { LoadNextScene(); }
            else { timePressingAllFourCorners = 0f; }
        }
    }

    private void LoadNextScene()
    {
        SceneManager.LoadScene(sceneToLoad);
    }
}
