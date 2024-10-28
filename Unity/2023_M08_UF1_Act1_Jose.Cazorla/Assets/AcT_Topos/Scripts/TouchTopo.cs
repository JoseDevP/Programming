using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.EnhancedTouch;
using Touch = UnityEngine.InputSystem.EnhancedTouch.Touch;

public class TouchTopo : MonoBehaviour
{
    private void OnEnable()
    {
        EnhancedTouchSupport.Enable();
    }

    private void OnDisable()
    {
        EnhancedTouchSupport.Disable();
    }
    private void Update()
    {
        foreach (Touch t in Touch.activeTouches)//recorrer todo dentro de Touch.activeTouches  realizamos una accion
        {
            if(t.began)
            {
                //control r m
                DebugDrawTouch(Camera.main.ScreenToWorldPoint((Vector3)t.screenPosition + Vector3.forward * 10f));
                Ray ray = Camera.main.ScreenPointToRay(t.screenPosition);
                ProcessWhack(ray);
            }

        }
        if(Mouse.current.leftButton.isPressed)
        {
            DebugDrawTouch(Camera.main.ScreenToWorldPoint((Vector3)Mouse.current.position.value + Vector3.forward * 10f));
            Ray ray = Camera.main.ScreenPointToRay(Mouse.current.position.value);
            ProcessWhack(ray);
        }
        
    }

    private static void ProcessWhack(Ray ray)
    {
        if (Physics.Raycast(ray, out RaycastHit hit))
        {
            if (hit.collider.CompareTag("Topo"))
            {
                Destroy(hit.collider.gameObject);
            }
        }
    }

    private static void DebugDrawTouch(Vector3 touchWorldPosition)
    {
        Debug.Log("Just touched");
        //Debug.LogWarning("Just touched");
        //Debug.LogError("Just touched");

        Vector3 worldPosition = touchWorldPosition;

     
        Debug.DrawLine(worldPosition + Vector3.left, worldPosition + Vector3.right, Color.red, 10f);
        Debug.DrawLine(worldPosition + Vector3.up, worldPosition + Vector3.down, Color.red, 10f);

        //Debug.DrawLine;
    }

}
