using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Video;

public class HowToVideo : MonoBehaviour
{
    [SerializeField] VideoPlayer videoplayer;
    public void OnPlay()
    {
        Debug.Log("OnPlay");
        videoplayer.Play();
        Debug.Log("OnPlay - Finished");

    }

    public void OnRestart()
    {
        int a = 10;
        int b = 20;
        int c = a + b;
        int d = c / b;

        Debug.Log("OnReStart");
        videoplayer.Stop();
        videoplayer.Pause();
        Debug.Log("OnReStart - Finished");

    }

    public void OnStop()
    {
        Debug.Log("OnStop");
        videoplayer.Pause();
        Debug.Log("OnStop - Finished");
    }
}
