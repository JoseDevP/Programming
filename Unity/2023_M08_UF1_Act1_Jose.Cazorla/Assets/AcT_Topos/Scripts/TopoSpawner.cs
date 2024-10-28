using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class TopoSpawner : MonoBehaviour
{
    public GameObject TopoPrefab;
    public float delay;

    private bool active;

    private float time;
    // Start is called before the first frame update
    void Start()
    {
        time = 0;
        active = true;
    }

    // Update is called once per frame
    void Update()
    {
        if (active)
        {
            time += Time.deltaTime;
            if (time > delay)
            {
                GameObject Topo = Instantiate(TopoPrefab, transform.position, Quaternion.identity);
                Topo.transform.position= new Vector3(Random.Range(-2.0f, 2.0f), Random.Range(6.0f, -4.0f), 0);
                time = 0;
            }
        }
    }

    public void StopSpawner()
    {
        active = false;
    }

    public void StartSpawner()
    {
        active = true;
    }
}
